N = 1000

(0..N).each do |i|
  puts "#define inc_#{i} #{i + 1}"
end

puts '#define dec_0 0'

(1..N).each do |i|
  puts "#define dec_#{i} #{i - 1}"
end

puts '#define is_pos_0 0'

(1..N).each do |i|
  puts "#define is_pos_#{i} 1"
end
