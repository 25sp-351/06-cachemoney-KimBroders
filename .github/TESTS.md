Test for thousands, hundreds, dollars, cents: 
    input: 125647
    expected output: 
        Money: 125647 = one thousand two hundred fifty-six dollars and forty-seven cents


Test for thousands, hundreds, dollars: 
    input: 125600
    expected output:
        Money: 125600 = one thousand two hundred fifty-six dollars

Test for thousands, hundreds, cents: 
    input: 120011
    expected output:
        Money: 120011 = one thousand two hundred dollars and eleven cents

Test for thousands, dollars, cents: 
    input: 101310
    expected output:
        Money: 101310 = one thousand thirteen dollars and ten cents

Test for hundreds, dollars, cents: 
    input: 040529
    expected output:
        Money: 40529 = four hundred five dollars and twenty-nine cents


Test for thousands, hundreds: 
    input: 120000
    expected output:
        Money: 120000 = one thousand two hundred dollars

Test for thousands, dollars: 
    input: 101300
    expected output:
        Money: 101300 = one thousand thirteen dollars

Test for thousands, cents: 
    input: 100065
    expected output:
        Money: 100065 = one thousand dollars and sixty-five cents

Test for hundreds, dollars: 
    input: 040500
    expected output:
        Money: 40500 = four hundred five dollars

Test for hundreds, cents: 
    input: 040099
    expected output:
        Money: 40099 = four hundred dollars and ninety-nine cents

Test for dollars, cents: 
    input: 008839
    expected output:
        Money: 8839 = eighty-eight dollars and thirty-nine cents


Test for thousands: 
    input: 100000
    expected output:
        Money: 100000 = one thousand dollars

Test for hundreds: 
    input: 040000
    expected output:
        Money: 40000 = four hundred dollars

Test for dollars: 
    input: 008800
    expected output:
        Money: 8800 = eighty-eight dollars

Test for cents: 
    input: 000042
    expected output:
        Money: 42 = forty-two cents


Test for hundreds, one dollar, one cent: 
    input: 040101
    expected output:
        Money: 40101 = four hundred one dollars and one cent

Test for dollars, one cent: 
    input: 008801
    expected output:
        Money: 8801 = eighty-eight dollars and one cent

Test for one dollar, cents: 
    input: 000116
    expected output:
        Money: 116 = one dollar and sixteen cents


Test for one dollar, one cent: 
    input: 000101
    expected output:
        Money: 101 = one dollar and one cent

Test for one dollar: 
    input: 000100
    expected output:
        Money: 100 = one dollar

Test for one cent: 
    input: 000001
    expected output:
        Money: 1 = one cent

Test for no cents: 
    input: 000000
    expected output:
        Money: 0 = zero dollars