extends Node
class_name Geo

const R := 63.78137
const F_INV := 298.257224
const F := 1.0 / F_INV

var latitude: float :
	set(value):
		latitude = value
		_vector = Vector3.ZERO

var longitude: float :
	set(value):
		longitude = value
		_vector = Vector3.ZERO

var altitude: float :
	set(value):
		altitude = value
		_vector = Vector3.ZERO

var _vector: Vector3 = Vector3.ZERO
var vector: Vector3 :
	get:
		if _vector == Vector3.ZERO:
			_vector = _to_vector(latitude, longitude, altitude)
		return _vector
	set(value):
		var g: Array[float] = _from_vector(value)
		latitude = g[0]
		longitude = g[1]
		altitude = g[2]
		_vector = value

# FROM: https://stackoverflow.com/questions/18759601/converting-lla-to-xyz
static func _to_vector(latitude: float, longitude: float, altitude: float) -> Vector3:
	var cosLat := cos(latitude * PI / 180)
	var sinLat := sin(latitude * PI / 180)
	var cosLong := cos(longitude * PI / 180)
	var sinLong := sin(longitude * PI / 180)
	
	var c := 1 / sqrt(cosLat * cosLat + (1 - F) * (1 - F) * sinLat * sinLat)
	var s := (1 - F) * (1 - F) * c

	var x := (R * c + altitude) * cosLat * cosLong
	var y := (R * c + altitude) * cosLat * sinLong
	var z := (R * s + altitude) * sinLat

	return Vector3(x, y, z)

static func _from_vector(vector: Vector3) -> Array[float]:
	return []

static func Create(latitude: float, longitude: float, altitude: float) -> Geo:
	var new: Geo = Geo.new()
	new.latitude = latitude
	new.longitude = longitude
	new.altitude = altitude
	return new

static func FromVector(vector: Vector3) -> Geo:
	var g: Array[float] = _from_vector(vector)
	var new: Geo = Geo.Create(g[0], g[1], g[2])
	new._vector = vector
	return new
