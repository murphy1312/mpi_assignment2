$nodes = 4;
$array_size = 1000;
while($array_size -le 4000000)
{
mpiexec -n $nodes E:\Daten\Dublin\Kurse\DistributedSystems\Assignment2\x64\Debug\ConsoleApplication1.exe $array_size | Out-File Outputfile_4node_400.txt -Append
$array_size = $array_size + 1000;
}
