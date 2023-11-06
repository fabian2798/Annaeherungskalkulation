import math

epsilon = 0.0000001  # annährungswert der Schiffe
x_p = 0.0  # x - koordinate piratenschiff
y_p = 0.0  # y - koordinate piratenschiff
v_p = 1.0  # geschwindigkeit piratenschiff
x_h = 1.0  # x - koordinate handelsschiff
y_h = 0.0  # y - koordinate handelsschiff
v_h = 0.75  # geschwindigkeit handelsschiff
repeat = 0  # anzahl an durchgängen
delta_t = 0.0000001
time = 0
delta_x = delta_t  # zurückgelegter weg auf x - achse
delta_y = 0.0  # zurückgelegter weg auf y - achse
phi = 0.0  # steigerungswinkel

while (x_h - x_p) > epsilon or (y_h - y_p) > epsilon:
    repeat += 1  # k
    time = delta_t * repeat
    y_h = delta_t * repeat * v_h
    x_p = x_p + delta_x  # akutelle x_pos
    y_p = y_p + delta_y  # aktuelle y_pos
    if x_p != 1:
        phi = math.atan((y_h - y_p) / (1 - x_p))
    else:
        phi = math.pi / 2
    # arctan des winkels phi == ankathete / gegenhathete, gibt winkel in radius zurück
    delta_x = delta_t * math.cos(phi)  # x_pos veränderung nach einer bestimmten zeit
    delta_y = delta_t * math.sin(phi)  # y_pos veränderung nach einer bestimmten zeit

print("Die Schiffe treffen sich bei y: " + str(y_p))
print("Nach einer Zeit von t: " + str(time))
