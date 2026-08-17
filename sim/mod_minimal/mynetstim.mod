: $Id: netstim.mod 2212 2008-09-08 14:32:26Z hines $
: comments at end

NEURON {
  ARTIFICIAL_CELL MyNetStim
  THREADSAFE
  RANGE interval, number, start
  RANGE noise
  RANGE sid, cid
  RANGE xpos, ypos, zpos, gid, randi
}

PARAMETER {
	interval	= 10 (ms) <1e-9,1e9> : time between spikes (msec)
	number		= 10 <0,1e9> : number of spikes (independent of noise)
	start		= 50 (ms) : start of first spike
	noise		= 0 <0,1> : amount of randomness (0.0 - 1.0)
	sid = -1 (1) : synapse id, from cell template
	cid = -1 (1) : id of cell to which this synapse is attached
	xpos = 0
	ypos = 0
	zpos = 0
	gid = 0
	randi = 0
}

ASSIGNED {
	event (ms)
	on
	ispike
}

INITIAL {
	on = 0 : off
	ispike = 0
	if (noise < 0) {
		noise = 0
	}
	if (noise > 1) {
		noise = 1
	}
	if (start >= 0 && number > 0) {
		on = 1
		event = start + invl(interval) - interval*(1. - noise)
		if (event < 0) {
			event = 0
		}
		net_send(event, 3)
	}
}

PROCEDURE init_sequence(t(ms)) {
	if (number > 0) {
		on = 1
		event = 0
		ispike = 0
	}
}

FUNCTION is_art() {
	is_art = 1
}

PROCEDURE position(a, b, c) {
	xpos = a
	ypos = b
	zpos = c
}

FUNCTION invl(mean (ms)) (ms) {
	if (mean <= 0.) {
		mean = .01 (ms)
	}
	if (noise == 0) {
		invl = mean
	}else{
		invl = (1. - noise)*mean + noise*mean*exprand(1)
	}
}

FUNCTION next_noise() {
	next_noise = exprand(1)
}

PROCEDURE next_invl() {
	if (number > 0) {
		event = invl(interval)
	}
	if (ispike >= number) {
		on = 0
	}
}

NET_RECEIVE (w) {
	if (flag == 0) { : external event
		if (w > 0 && on == 0) { : turn on spike sequence
			init_sequence(t)
			next_invl()
			event = event - interval*(1. - noise)
			net_send(event, 1)
		}else if (w < 0) { : turn off spiking definitively
			on = 0
		}
	}
	if (flag == 3) { : from INITIAL
		if (on == 1) { : but ignore if turned off by external event
			init_sequence(t)
			net_send(0, 1)
		}
	}
	if (flag == 1 && on == 1) {
		ispike = ispike + 1
		net_event(t)
		next_invl()
		if (on == 1) {
			net_send(event, 1)
		}
	}
}

COMMENT
Presynaptic spike generator
---------------------------

Simple compatibility copy of the old NetStim-style artificial cell.
It generates periodic or noisy spike trains using the legacy exprand path.

ENDCOMMENT

