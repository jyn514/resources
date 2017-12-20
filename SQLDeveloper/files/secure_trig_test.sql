  IF (TO_CHAR(SYSDATE, 'DY') IN ('SAT', 'SUN')) OR
   (TO_CHAR(SYSDATE, 'HH24')
   NOT BETWEEN '08' and '10') THEN
     IF DELETING THEN 
	RAISE_APPLICATION_ERROR(-20502,
        'You may delete from EMPLOYEES table only during business hours.');
     ELSIF INSERTING THEN
	RAISE_APPLICATION_ERROR(-20500,
	'You may insert into EMPLOYEES table only during business hours.');
     ELSIF UPDATING('SALARY') THEN
        RAISE_APPLICATION_ERROR(-20503, 
	'You may update SALARY only during business hours.');
     ELSE 
        RAISE_APPLICATION_ERROR(-20504, 
	'You may update EMPLOYEES table only during normal hours.');	
     END IF;
END IF;

Delete from employees where employee_id=350;

insert into employees(employee_id, last_name, first_name, email, hire_date, job_id)
values (300, 'Stephen', 'James', 'jstephen', '14-Jun-05', prod_exec');

update employees set salary=8000 where employee_id = 200;