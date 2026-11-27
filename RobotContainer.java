GenericHID buttonBox = new GenericHID(1); //1 is a placeholder, check DS USB port #

//Trigger different automated commands for each button

new JoystickButton(buttonBox, 1).onTrue(new buttonBoxCommandPlaceholder1());
new JoystickButton(buttonBox, 2).onTrue(new buttonBoxCommandPlaceholder2());
new JoystickButton(buttonBox, 3).onTrue(new buttonBoxCommandPlaceholder3());
new JoystickButton(buttonBox, 4).onTrue(new buttonBoxCommandPlaceholder4());
new JoystickButton(buttonBox, 5).onTrue(new buttonBoxCommandPlaceholder5());
