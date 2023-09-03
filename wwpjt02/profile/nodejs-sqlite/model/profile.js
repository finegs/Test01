// represents the  model
const { Model, DataTypes } = require("sequelize");
const sequelize = require("./dbconfig");

class Profile extends Model {}

Profile.init(
  {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true
    },
    name: {
      type: DataTypes.STRING
    },
    email: {
      type: DataTypes.STRING
    },
    phone: {
      type: DataTypes.STRING
    }
  },
  {
    sequelize,
    modelName: "profile",
    timestamps: false
  }
);

module.exports = Profile;
