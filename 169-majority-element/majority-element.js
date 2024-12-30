var majorityElement = function (nums) {
    let majorityElement = 0, counter = 0;
    for (let i = 0; i < nums.length; i++) {
        if (counter == 0) {
            majorityElement = nums[i];
            counter = 1;
        }
        else if (majorityElement == nums[i]) {
            counter++;
        }
        else {
            counter--;
        }
    }
    return majorityElement;
};