local svision = require "svision"
local image,error = svision.loadImage("./test/test.png")
assert(image,error)
assert(svision.getColor(image,202,174) == 0xefb020)
assert(image:getColor(202,174) == 0xefb020)
assert(image:getColor(359,158) == 0x164D65)
assert(image:getColor(156,176) == 0x73151f)
