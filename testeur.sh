echo "\n############################\n\nEasy test :"
ARG="2 1 0";
echo '\nARG = "2 1 0"';
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG="1 5 2 4 3";
echo '\nARG = "1 5 2 4 3"';
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
echo '\nARG = random[0:4]';
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`;
echo "\nTEST 1";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`;
echo "\nTEST 2";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`;
echo "\nTEST 3";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"

echo "\n############################\n\nMandatory test :"
echo 'ARG = random[0:99]';
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
echo "\nTEST 1";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
echo "\nTEST 2";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
echo "\nTEST 3";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
echo "\nTEST 4";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
echo "\nTEST 5";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"

echo "\n############################\n\nHard test :"
echo 'ARG = random[0:499]';
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
echo "\nTEST 1";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
echo "\nTEST 2";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
echo "\nTEST 3";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
echo "\nTEST 4";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
echo "\nTEST 5";
printf "*--------------------------*\nchecker         ->      ";
./push_swap $ARG | ./checker_Mac.dms $ARG;
printf "\nnb instructions ->";
./push_swap $ARG | wc -l;
printf "*--------------------------*\n"