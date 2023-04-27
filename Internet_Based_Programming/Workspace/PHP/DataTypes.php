<?
    $intNum = 472;
    $doubleNum = 2.31;
    $boolean = true;
    $string = 'String';
    $array = array("Istanbul", "Ankara", "Bolu");
    class person{
        public $name = "Name";
        function agePrint(){
            $age = 5;
            echo "Age = $age <br />";
        }
    }
    $object = new person();

    $object->agePrint();
    echo $object->name . "<br />";
    echo $intNum . "<br />";
    echo $doubleNum . "<br />";
    echo $boolean . "<br />";
    echo $string . "<br />";
    echo $array . "<br />";
?>
