use std::collections::HashSet;

#[derive(Debug)]
struct LenAndSet {
    len: i32,
    set: HashSet<char>
}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut ans = 0;
        let mut len_and_set = LenAndSet {
            len: 0,
            set: HashSet::new()
        };
        let mut last = 0;
        for (i, c) in s.chars().enumerate() {
            if !len_and_set.set.contains(&c) {
                len_and_set.len += 1;
                len_and_set.set.insert(c);
            }
            else {
                let mut found = false;
                for (j, tmp) in s[last..i].chars().rev().enumerate() {
                    if found {
                        len_and_set.set.remove(&tmp);
                    }
                    if tmp == c {
                        last = i - j;
                        len_and_set.len = j as i32 + 1;
                        found = true;
                    }
                }
            }
            if len_and_set.len > ans {
                ans = len_and_set.len;
            }
            // println!("{:?}", len_and_set);
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn case() {
        use super::*;
        // let ans = Solution::length_of_longest_substring("abccba".to_string());
        // assert_eq!(ans, 3);

        let ans = Solution::length_of_longest_substring("dvdfda".to_string());
        assert_eq!(ans, 3);
    }
}

struct Solution;
fn main() {}