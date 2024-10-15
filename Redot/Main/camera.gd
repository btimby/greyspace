extends Camera3D

var speed : float = 0.01
var movement : float = 0.0

func _ready() -> void:
	self.position = Vector3(100, 100, 100)
	self.look_at(Vector3.ZERO)

func _process(delta: float) -> void:
	if self.movement == 0.0:
		return
	self.position = lerp(self.position, Vector3.ZERO, self.movement)

func _input(event: InputEvent) -> void:
	if event.is_action_pressed('key_up'):
		self.movement = self.speed
	elif event.is_action_pressed('key_down'):
		self.movement = -self.speed
	else:
		self.movement = 0.0
