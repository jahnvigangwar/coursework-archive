
-- Login for customer
DECLARE 
    PROCEDURE loginCustomer_library(user IN VARCHAR2, pass IN VARCHAR2) 
    IS 
      passAux customer.password%TYPE; 
      incorrect_password EXCEPTION; 
    BEGIN 
      SELECT password INTO passAux 
      FROM customer 
      WHERE username LIKE user; 
       
      IF passAux LIKE pass THEN 
        DBMS_OUTPUT.PUT_LINE('User ' || user || ' loging succesfull'); 
      ELSE 
        RAISE incorrect_password; 
      END IF; 
       
      EXCEPTION 
      WHEN no_data_found OR incorrect_password THEN  
           DBMS_OUTPUT.PUT_LINE('Incorrect username or password'); 
                                        
    END; 
BEGIN 
  loginCustomer_library('al1','alfred123'); 
END;

-- Login for Employee
DECLARE 
  PROCEDURE loginEmployee_library(user IN VARCHAR2, pass IN VARCHAR2) 
  IS 
    passAux employee.password%TYPE; 
   incorrect_password EXCEPTION; 
  BEGIN 
    SELECT password INTO passAux 
    FROM employee 
    WHERE username LIKE user; 
    IF passAux LIKE pass THEN 
     DBMS_OUTPUT.PUT_LINE('User ' || user || ' loging succesfull'); 
    ELSE 
    RAISE incorrect_password; 
    END IF; 
    EXCEPTION 
      WHEN no_data_found OR incorrect_password THEN  
           DBMS_OUTPUT.PUT_LINE('Incorrect username or password'); 
    END; 
BEGIN 
  loginEmployee_library('ro11','ross123'); 
END;
