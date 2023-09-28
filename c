 empModel.SomeField = QRCODEVAL + " - " + empModel.SomeField;

            // Call a method in your repository to save the model to the database
            _repository.SaveEmpModel(empModel); // Replace with your actual repository method
