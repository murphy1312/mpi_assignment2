
$n = 1000000;
$nodes = 8;
while($n -le 40000000)
{mpiexec -n $nodes E:\Daten\Dublin\Kurse\DistributedSystems\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe $n 
#| Out-File Outputfile_time8node.txt -Append
$n = $n + 1000000;}