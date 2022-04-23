local svision = require "svision"
local image,error = svision.loadImage("test.png")

assert(svision.getColor(image,202,174) == 0xefb020)
assert(image:getColor(202,174) == 0xefb020)
assert(image:getColor(401,159) == 0xffffff)

