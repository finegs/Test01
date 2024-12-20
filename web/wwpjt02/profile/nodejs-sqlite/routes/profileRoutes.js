// represents the router class
const express = require("express");
const {
  getAllProfiles,
  getProfile,
  saveProfile,
  deleteProfile,
  updateProfile
} = require("../controller/profileController");

const router = express.Router();

// http://localhost:3005/api/profiles
router.get("/profiles", getAllProfiles);

// http://localhost:3005/api/profile/id
router.get("/profile/:id", getProfile);

// http://localhost:3005/api/profile
/*
{
    "name": "{{$randomFullName}}",
    "email": "{{$randomEmail}}",
    "phone": "{{$randomPhoneNumber}}"
}
*/
router.post("/profile", saveProfile);

// http://localhost:3005/api/profile/id
/*
{
    "name": "{{$randomFullName}}",
    "email": "{{$randomEmail}}",
    "phone": "{{$randomPhoneNumber}}"
}
*/
router.put("/profile/:id", updateProfile);

// http://localhost:3005/api/profile/id
router.delete("/profile/:id", deleteProfile);

module.exports = {
  routes: router
};
