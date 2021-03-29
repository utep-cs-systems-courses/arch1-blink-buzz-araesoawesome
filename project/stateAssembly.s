	.arch msp430g2553

	.p2align 1,0
	.data

jt:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.text
	.global state_advance

state_advance:
	cmp #5, r12
	jc default
	add r12, r12
	mov jt(r12),r0

case1:
	call #mario_song
	call #redLights
	jmp end

case2:
	call #beethoven_5th
	call #greenLights
	jmp end

case3:
	call #path_of_wind
	call #path_of_wind
	call #bothLights
	jmp end

case4:
	call #song_of_storms
	call #bothLights
	jmp end

default:
	jmp end

end:
	ret
