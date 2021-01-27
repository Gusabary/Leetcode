struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for (i, x) in nums.iter().enumerate() {
            for (j, y) in nums[i + 1..].iter().enumerate() {
                if x + y == target {
                    return vec!(i as i32, (i + j + 1) as i32);
                }
            }
        }
        vec!()
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn case() {
        use super::*;
        let ans = Solution::two_sum(vec![3,3,], 6);
        assert_eq!(ans, vec![0,1,]);
    }
}

fn main() {}