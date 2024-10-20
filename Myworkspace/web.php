<?php
    //Establish connection with server
    $connection = mysqli_connect('localhost','root','','CourseRegDB');

    // //Selecting the DataBase
    // $selectdb = mysql_select_db("studentdb",$connection);


    if($_POST["ddlCRUDOp"]=="Create/Insert")
    {
            //Collection of web page data
          
            $stName = $_POST["txtusername"];
            $stemail = $_POST["txtemail"];
            $stpsw=$_POST["txtPassword"] ;
        $sqlquery = "INSERT into tbl_Registration(St_Name, St_Email,St_password ) 
        values('$stName','$stemail','$stpsw')" ;
    
            //Execute SQL Statements
            $exequery = mysqli_query($connection, $sqlquery);
            if($exequery)
            {
                echo "<span style=\"color:Red\"><p><b><center>New Record created sucessfully</center></b></p></span>"."<br/>";
                echo "<center><a href=\"sign_up_page.html\">&lt-Back</a></center>";
            }
            else
            {
                echo "Exception!!! not able to execute query";
            }

            mysqli_close($connection);	
    }
    else if($_POST["ddlCRUDOp"]=="Read/Display")
    {
        $stUSN = $_POST["ddl_usn"];
            //prepare SQL statements
            $selectquery = "SELECT * FROM tbl_Registration where St_Email='".$stemail."'";

            //execute SQL query
            $exequery = mysqli_query($connection, $selectquery) ;
            //print_r($exequery);
            if($exequery)
            {
                echo "<table border=\"1\">
                        <tr>
                            <th>User Name</th>
                            <th>Email</th>
                            <th>Password</th>
                            
                        </tr>";
                while($row = mysqli_fetch_array($exequery))
                {
                    echo "<tr>";
                    echo "<td>".$row['St_Name']."</td>";
                    echo "<td>".$row['St_Email']."</td>";
                    echo "<td>".$row['St_Password']."</td>";
                    echo "</tr>";
                }
                echo "<tr><td colspan=\"5\" align=\"center\"><a href=\"sign_up_page.html\">&lt-Back</a></td></tr></table>";
            }
            else{
                echo "<span style=\"color:Red\"><p><b><center>Record not found!!!! Try with some other input</center></b></p></span>"."<br/>";
                echo "<center><a href=\"sign_up_page.html\">&lt-Back</a></center>";
                mysqli_close($connection);
        }
    }
    else if($_POST["ddlCRUDOp"]=="Update")
    {
        //Collection of web page data
        $courseVal = null;
        $stName = $_POST["txtname"];
        $stemail= $_POST["txtemail"];
        $stpsw=$_POST["txtPassword"];
        //Prepare SQL query
        $updatequery = "UPDATE tbl_Registration SET St_Name='$stName',St_Email='$stemail',St_Password='$stpsw WHERE St_Email='$stemail'";
        
        //execute SQL query
        $exeupdatequery = mysqli_query($connection, $updatequery);


        if($exeupdatequery)
        {
            echo "<span style=\"color:Red\"><p><b><center>Record updated sucessfully</center></b></p></span>"."<br/>";
            echo "<center><a href=\"sign_up_page.html\">&lt-Back</a></center>";
        }
        else
        {
            echo "Excpetion!! not able to execute SQL query";
        }
        mysqli_close($connection);
    }
    else if($_POST["ddlCRUDOp"]=="Delete")
    {
        $stUSN = $_POST["ddl_usn"];
        //Prepared statements
        $deleteQuery = "DELETE from tbl_Registration WHERE St_email='$stemail'";
        
        //execute Query
        $exedeletequery = mysqli_query($connection, $deleteQuery);

        if($exedeletequery)
        {
            echo "<span style=\"color:Red\"><p><b><center>Record Deleted sucessfully</center></b></p></span>"."<br/>";
            echo "<center><a href=\"sign_up_page.html\">&lt-Back</a></center>";
        }
        else
        {
            echo "Exception!!!, Record not deleted";
        }
    mysqli_close($connection);
    }
?>