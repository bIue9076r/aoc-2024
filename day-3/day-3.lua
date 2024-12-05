string = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"

multbl = {}
index = 1

for i = 1,#string do
	if string:sub(i,i+4) == "mul(" then
		j = 1
		while (not(string:sub(i+5+j,i+5+j) == ")")) and (j < 9) do
			
			j = j + 1
		end
	end
end