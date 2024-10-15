extends Node
class_name Cell

var vertices: Array[Geo] = []

static func Create(vertices: Array[Geo]) -> Cell:
	var new: Cell = Cell.new()
	new.vertices = vertices
	return new

func get_triangles() -> Array[Array]:
	var triangles: Array[Array] = [
		[self.vertices[1].vector, self.vertices[2].vector, self.vertices[3].vector],
		[self.vertices[1].vector, self.vertices[3].vector, self.vertices[4].vector],
	]
	if self.vertices.size() == 6:
		triangles.append(
			[self.vertices[0].vector, self.vertices[1].vector, self.vertices[5].vector]
		)
		triangles.append(
			[self.vertices[1].vector, self.vertices[4].vector, self.vertices[5].vector]
		)
	else:
		triangles.append(
			[self.vertices[0].vector, self.vertices[1].vector, self.vertices[4].vector]
		)
	return triangles

func get_lines() -> Array[Array]:
	var lines : Array[Array] = [
		[self.vertices[0].vector, self.vertices[1].vector],
		[self.vertices[1].vector, self.vertices[2].vector],
		[self.vertices[2].vector, self.vertices[3].vector],
		[self.vertices[3].vector, self.vertices[4].vector]
	]
	if self.vertices.size() == 6:
		lines.append(
			[self.vertices[4].vector, self.vertices[5].vector]
		)
		lines.append(
			[self.vertices[5].vector, self.vertices[0].vector]
		)
	else:
		lines.append(
			[self.vertices[4].vector, self.vertices[0].vector]
		)
	return lines
