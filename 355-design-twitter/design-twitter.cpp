class Twitter {
public:
    // Declaring set for storing unique users and vector<pair<int,int>>tweet ,
    // for storing tweets globally where first = tweet id , second = user.id

    unordered_set<int> user[501];
    vector<pair<int, int>> tweet; //(tweetid , userid)
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweet.push_back({tweetId, userId});
    }

    vector<int> getNewsFeed(int userId) {
        // here i want to show all the recent 10 tweet of user + account that
        // user follows
        int t = tweet.size(); // tweet vector size
        vector<int> ans;      // for storing 10 tweet
        // will traverse backward to get recend 10 tweet , as they will be the
        // one added at the last
        for (int i = t - 1; i >= 0 && ans.size() < 10; i--) {
            if (tweet[i].second == userId ||
                user[userId].count(
                    tweet[i]
                        .second)) { // means user.id ki following mai is
                                    // particular tweet ki user.id exist krti
                                    // hai , if yes include this tweet in ans
                ans.push_back(tweet[i].first);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        user[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */