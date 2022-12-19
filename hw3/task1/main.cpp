class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(const int left_bound, const int right_bound ) {
    if (right_bound < left_bound) {
        return {nullptr};
    }

    vector<TreeNode*> answer;
    
    // пройдемся по каждому числу как по корню на данном уровне
    for (int current_root = left_bound; current_root <= right_bound; current_root++) {
        // получим все возможные деревья справа и слева
        const auto left_subtrees = dfs(left_bound, current_root - 1);
        const auto right_subtrees = dfs(current_root + 1, right_bound);

        // подставим все возмождные варианты к корню current_root
        for (const auto left_subtree: left_subtrees) {
            for (const auto right_subtree: right_subtrees) {
                answer.emplace_back(new TreeNode(current_root, left_subtree, right_subtree));
            }
        }
    }

    return answer;
}
};