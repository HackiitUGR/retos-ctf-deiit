socat TCP-LISTEN:31337,reuseaddr,fork \
	EXEC:"/usr/bin/timeout 60 /challenge/buffer_overflow1",stderr
