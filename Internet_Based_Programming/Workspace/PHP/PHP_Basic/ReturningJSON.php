<?php
    header("Content-type: application/json; charset=utf-8");
    $data = ["response" => "Hello Word!"];
    echo json_encode($data);

