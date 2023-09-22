 [HttpPost]
        public ActionResult SearchByRefcode(string refcodeSearchBox)
        {
            try
            {
                // Call the stored procedure to search by REFCODE
                List<EmpModel> searchResults = empRepo.SearchByRefcode(refcodeSearchBox);

                // Pass the search results to a partial view
                return PartialView("_SearchResults", searchResults);
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }

