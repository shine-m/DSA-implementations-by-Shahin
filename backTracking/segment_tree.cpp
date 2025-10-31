#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class segment_tree
{
public:
    vector<int> &storage_array, tree_nodes;
    int tree_size, storagearray_size;
    int construct_tree(int, int, int);
    void print_segmentTree();
    int range_sum(int, int, int, int, int);
    void print_array();
    void update(int, int, int, int, int);
    int calculate_sum(int l, int r)
    {
        // parameters were in 1 based index, converting to o based
        cout << "Summation in range " << l << " to " << r << " is ";
        l--;
        r--;
        return range_sum(0, 0, storagearray_size - 1, l, r);
    }
    void update_tree(int index, int val)
    {
        index--; // converting 0base index , assuming input was 1 based index
        int difference = val - storage_array[index];
        storage_array[index] = val;
        update(0, 0, storagearray_size - 1, index, difference);
    }

    segment_tree(vector<int> &v) : storage_array(v)
    {
        storagearray_size = v.size(); // size will be 2*N -1 { n for leaves , n+1 for internal nodes}
        tree_size = 2 * storagearray_size - 1;
        tree_nodes = vector<int>(tree_size);
    }
};
int main()
{
    system("cls");
    cout << ln << ln;

    vector<int> v = {4, 1, 2, 4, 6, 3, 1, 8, 7};
    segment_tree obj(v);
    obj.print_array();
    obj.construct_tree(0, 0, v.size() - 1);
    obj.print_segmentTree();
    cout << obj.calculate_sum(6, 9);

    obj.update_tree(3, 9);

    cout << "\nUpdated\n";
    obj.print_array();
    obj.print_segmentTree();

    cout << ln << ln << ln;
    return 0;
}

int segment_tree ::construct_tree(int i, int l, int r)
{
    if (l == r)
    {
        return (tree_nodes[i] = storage_array[l]);
    }
    int mid = (l + r) / 2;
    return tree_nodes[i] = construct_tree(2 * i + 1, l, mid) + construct_tree(2 * i + 2, mid + 1, r);
}

void segment_tree::print_array()
{
    cout << "The Input Array is ";
    for (auto &i : this->storage_array)
    {
        cout << i << " ";
    }
    cout << ln;
}

int segment_tree::range_sum(int i, int current_l, int current_r, int find_l, int find_r)
{

    // cout << i << " " << current_l << "" << current_r << "calling\n";
    if (current_l >= find_l && current_r <= find_r)
        return tree_nodes[i];
    if (current_l > find_r || current_r < find_l)
        return 0;
    int mid = (current_l + current_r) / 2;
    return range_sum(2 * i + 1, current_l, mid, find_l, find_r) + range_sum(2 * i + 2, mid + 1, current_r, find_l, find_r);
}

void segment_tree::print_segmentTree()
{
    cout << "The built tree ";
    for (auto &i : tree_nodes)
    {
        cout << i << " ";
    }
    cout << ln;
}

void segment_tree::update(int i, int l, int r, int index, int difference)
{

    if (l > index || r < index)
        return;

    tree_nodes[i] += difference;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    update(2 * i + 1, l, mid, index, difference);
    update(2 * i + 2, mid + 1, r, index, difference);
}