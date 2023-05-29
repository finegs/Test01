/* eslint-env node */
module.exports = {
  root: true,
  'extends': [
    'plugin:vue/vue3-essential',
    'eslint:recommended'
  ],
  parserOptions: {
    ecmaVersion: 'latest'
  },
  rules: {
    'semi': 'off',
    'camelcase': 'off',
    "prettier/prettier": [
      "error",
      {
        "endOfLine": "auto",
        "printWidth": 160,
      }
    ]
  }
}