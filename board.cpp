#include "include/board.hpp"

using namespace std;

int Tile::getValue(void) const {
	if (!hasValue()) {
		throw out_of_range("Tile does not contain a value.");
	}
	return value;
}

/**
 * throws std::invalid_argument if argument is not in 1 to 9
 */
void Tile::setValue(int val) {
	if (val < 1 || val > 9) {
		throw invalid_argument("Invalid Tile value.");
	}
	value = val;
}

bool Tile::hasValue(void) const {
	return value != 0;
}

void Tile::clearValue(void) {
	value = 0;
}


/**
 * throws std::out_of_range if x or y argument is not in 0 to 2
 */
int Cluster::getTileValue(int x, int y) const {
	if (x < 0 || x > 2 || y < 0 || y > 2) {
		throw out_of_range("Tile coordinates outside valid range within cluster.");
	}
	return tiles[x][y].getValue();
}

/**
 * throws std::out_of_range if x or y argument is not in 0 to 2
 * throws std::invalid_argument if val is not in 1 to 9
 * throws std::runtime_error if the cluster already contains value
 */
void Cluster::setTileValue(int x, int y, int val) {
	if (x < 0 || x > 2 || y < 0 || y > 2) {
		throw out_of_range("Tile coordinates outside valid range within cluster.");
	}
	if (val < 1 || val > 9) {
		throw invalid_argument("Invalid Tile value.");
	}
	if (inCluster.find(val) != inCluster.end()) {
		throw runtime_error("Cluster already has value.");
	}
	tiles[x][y].setValue(val);
	inCluster.insert(val);
}

/**
 * throws std::out_of_range if x or y argument is not in 0 to 2
 */
void Cluster::clearTileValue(int x, int y) {
	if (x < 0 || x > 2 || y < 0 || y > 2) {
		throw out_of_range("Tile coordinates outside valid range within cluster.");
	}
	inCluster.erase(tiles[x][y].getValue());
	tiles[x][y].clearValue();
}

/**
 * throws std::invalid_argument if val is not in 1 to 9
 */
bool Cluster::clusterHasValue(int val) const {
	if (val < 1 || val > 9) {
		throw invalid_argument("Invalid Tile value.");
	}
	return inCluster.find(val) != inCluster.end();
}

/**
 * throws std::out_of_range if x is not in 0 to 2
 */
unordered_set<int> Cluster::getColValues(int x) const {
	unordered_set<int> values;

	if (x < 0 || x > 2) {
		throw out_of_range("Column index out of range.");
	}
	for (int y = 0; y < 3; y++) {
		if (tiles[x][y].getValue() != 0) {
			values.insert(tiles[x][y].getValue());
		}
	}
	return values;
}

/**
 * throws std::out_of_range if y is not in 0 to 2
 */
unordered_set<int> Cluster::getRowValues(int y) const {
	unordered_set<int> values;

	if (y < 0 || y > 2) {
		throw out_of_range("Row index out of range.");
	}
	for (int x = 0; x < 3; x++) {
		if (tiles[x][y].getValue() != 0) {
			values.insert(tiles[x][y].getValue());
		}
	}
	return values;
}

unordered_set<int> Cluster::getClusterSet(void) const {
	return inCluster;
}


/**
 * throws std::out_of_range if x is not in 0 to 8
 */
unordered_set<int> Board::getColumn(int x) const {
	unordered_set<int> values;
	unordered_set<int> clusterCol;

	if (x < 0 || x > 8) {
		throw out_of_range("Column number outside of range.");
	}
	for (int i = 0; i < 3; i++) {
		clusterCol = clusters[x / 3][i].getColValues(x % 3);
		values.insert(clusterCol.begin(), clusterCol.end());
	}
	return values;
}

/**
 * throws std::out_of_range if y is not in 0 to 8
 */
unordered_set<int> Board::getRow(int y) const {
	unordered_set<int> values;
	unordered_set<int> clusterRow;

	if (y < 0 || y > 8) {
		throw out_of_range("Row number outside of range.");
	}
	for (int i = 0; i < 3; i++) {
		clusterRow = clusters[i][y / 3].getRowValues(y % 3);
		values.insert(clusterRow.begin(), clusterRow.end());
	}
	return values;
}

/**
 * throws std::out_of_range if x or y is not in 0 to 2
 */
unordered_set<int> Board::getClusterSet(int x, int y) const {
	if (x < 0 || x > 2 || y < 0 || y > 2) {
		throw out_of_range("Cluster coordinates outside of range.");
	}
	return clusters[x][y].getClusterSet();
}

unordered_set<int> Board::getMissingValues(const unordered_set<int>& s) const {
	unordered_set<int> result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	result.erase(s.begin(), s.end());
	return result;
}

/**
 * throws std::out_of_range if x or y are not in 0 to 8
 */
unordered_set<int> Board::getPossibleValues(int x, int y) const {
	unordered_set<int> values, temp;

	if (x < 0 || x > 8 || y < 0 || y > 8) {
		throw out_of_range("Tile coordinate is outside of range.");
	}
	values = clusters[x / 3][y / 3].getClusterSet();

	temp = clusters[x / 3][y / 3].getColValues(x % 3);
	values.insert(temp.begin(), temp.end());

	temp = clusters[x / 3][y / 3].getRowValues(y % 3);
	values.insert(temp.begin(), temp.end());

	values = getMissingValues(values);
	return values;
}

/**
 * throws std::out_of_range if x or y are not in 0 to 8
 * throws std::invalid_argument if val is not in 1 to 9
 */
bool Board::isAssignmentLegal(int x, int y, int val) const {
	unordered_set<int> legalValues;

	if (x < 0 || x > 8 || y < 0 || y > 8) {
		throw out_of_range("Tile coordinate is outside of range.");
	}
	if (val < 1 || val > 9) {
		throw invalid_argument("Invalid Tile value.");
	}

	legalValues = getPossibleValues(x, y);
	if (legalValues.find(val) == legalValues.end()) {
		return false;
	}
	return true;
}

/**
 * throws std::out_of_range if x or y are not in 0 to 8
 * throws std::invalid_argument if val is not in 1 to 9
 * throws std::runtime_error if the coordinate/value assignment violates game rules
 */
void Board::setTileValue(int x, int y, int val) {
	if (x < 0 || x > 8 || y < 0 || y > 8) {
		throw out_of_range("Tile coordinate is outside of range.");
	}
	if (val < 1 || val > 9) {
		throw invalid_argument("Invalid Tile value.");
	}
	if (!isAssignmentLegal(x, y, val)) {
		throw std::runtime_error("Illegal value assignment; violates game rules.");
	}
	clusters[x / 3][y / 3].setTileValue(x % 3, y % 3, val);
}