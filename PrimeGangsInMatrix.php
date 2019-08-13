<?php
fscanf(STDIN, "%d\n", $number);
$str = '';
$visited = [];
for ($i = 0; $i < $number; $i++) {
    fscanf(STDIN, "%d %d", $m, $n);
    $arr = [];
    $visited = [];
    for($j = 0; $j < $m; $j++) {
        $nums = '';
        $str = fgets(STDIN);
        $arr[$j] = explode(" ", $str);
    }
    $prime_nums = flagPrimeNums($arr, $m, $n);
    $num = countFlaggedGangs($prime_nums, $m, $n);
    echo $num. PHP_EOL;
}

function flagPrimeNums(array $arr, int $m, int $n) {
    $primes_in_arr = [];
    for($i = 0; $i < $m; $i++){
        $primes_in_arr[$i] = [];
        for($j =0; $j < $n; $j++) {
            $primes_in_arr[$i][$j] = isPrime((int)$arr[$i][$j]);
        }
    }
    return $primes_in_arr;
}


function countFlaggedGangs(array $arr, int $m, int $n){
    global $visited;
    $count = 0;
    for($i = 0; $i < $m; $i++) {
        for($j = 0; $j < $n; $j++) {
            if(($visited[$i."-".$j] ?? false) || !$arr[$i][$j]) {
                continue;
            }
            
            flagThisGang($arr,  $m, $n, $i, $j);
            // print_r($visited);
            $count++;
        }
    }
    
    return $count;
}

function flagThisGang(array $arr, int $m, int $n, int $pos_m, int $pos_n) {
    global $visited;
    $visited[$pos_m."-".$pos_n] = true;
    if($arr[$pos_m][$pos_n] ?? false) {
        if($pos_m < $m && !($visited[($pos_m + 1)."-".($pos_n)] ?? false))
            flagThisGang($arr, $m, $n, $pos_m + 1, $pos_n);
        if($pos_m > 0 && !($visited[($pos_m - 1)."-".($pos_n)] ?? false))
            flagThisGang($arr, $m, $n, $pos_m - 1, $pos_n);
        if($pos_n < $n && !($visited[$pos_m."-".($pos_n + 1)] ?? false)) 
            flagThisGang($arr, $m, $n, $pos_m, $pos_n + 1);
        if($pos_n > 0 && !($visited[$pos_m."-".($pos_n - 1)] ?? false)) 
            flagThisGang($arr, $m, $n, $pos_m, $pos_n - 1);
    }
}

function isPrime(int $n) {
    static $static_primes = ['1' => false, '2' => true];
    if(($static_primes[$n] ?? false)) {
        return true;
    }
    if($n < 2) {
        $static_primes[$n] = false;
        return false;
    } else if($n % 2 == 0) {
        $static_primes[$n] = false;
        return false;
    }
    for($i = 3; $i <= sqrt($n); $i += 2) {
        if($n % $i == 0) {
            $static_primes[$n] = false;
            return false;
        }
    }
    $static_primes[$n] = true;
    return true;
}