// represents the jpa layer to fetch data from db
const Profile = require("../model/profile");

const getAllProfiles = async (req, res) => {
  const profiles = await Profile.findAndCountAll();
  res.send({
    context: profiles.rows,
    total: profiles.count
  });
};

const getProfile = async (req, res) => {
  const id = req.params.id;
  await Profile.findOne({ where: { id: id } }).then((item) => {
    if (item != null) {
      res.send(item);
    } else {
      res.sendStatus(404);
    }
  });
};

const saveProfile = async (req, res) => {
  const profile = {
    name: req.body.name,
    email: req.body.email,
    phone: req.body.phone
  };
  await Profile.create(profile).then(() => {
    res.sendStatus(201);
  });
};

const updateProfile = async (req, res) => {
  const id = req.params.id;
  await Profile.findByPk(id).then((item) => {
    if (item != null) {
      item
        .update({
          name: req.body.name,
          email: req.body.email,
          phone: req.body.phone
        })
        .then(() => {
          res.sendStatus(204);
        });
    } else {
      res.sendStatus(404);
    }
  });
};

const deleteProfile = async (req, res) => {
  const id = req.params.id;
  await Profile.findByPk(id).then((item) => {
    if (item != null) {
      item.destroy();
      res.sendStatus(200);
    } else {
      res.sendStatus(404);
    }
  });
};

module.exports = {
  getAllProfiles,
  getProfile,
  saveProfile,
  updateProfile,
  deleteProfile
};
