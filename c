[HttpPost]
        public ActionResult SearchByRefcode(string searchBox)
        {
            try
            {
                // Call the stored procedure to search by REFCODE
                List<EmpModel> searchResults = empRepo.SearchByRefcode(searchBox);

                // Pass the search results to a view
                return View("SearchResults", searchResults);
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }
