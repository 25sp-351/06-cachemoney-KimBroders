./main.exe < test-input.txt > test.out
if diff test-output.txt test.out; then
  echo "Success"
else
  echo "Failed"
fi