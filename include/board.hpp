#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <exception>
#include <unordered_set>
#include <vector>

class Cluster;

class Tile {
	friend Cluster;
	protected:
		int getValue(void) const;
		void setValue(int val);
		bool hasValue(void) const;
		void clearValue(void);
	private:
		int value = 0;
};

class Cluster {
	public:
		int getTileValue(int x, int y) const;
		void setTileValue(int x, int y, int value);
		void clearTileValue(int x, int y);
		bool clusterHasValue(int val) const;
		std::unordered_set<int> getClusterSet(void) const;
		std::unordered_set<int> getColValues(int x) const;
		std::unordered_set<int> getRowValues(int y) const;
	private:
		Tile tiles[3][3];
		std::unordered_set<int> inCluster;

};

class Board {
	public:
		std::unordered_set<int> getColumn(int x) const;
		std::unordered_set<int> getRow(int y) const;
		std::unordered_set<int> getClusterSet(int x, int y) const;
		std::unordered_set<int> getMissingValues(const std::unordered_set<int>& s) const;
		std::unordered_set<int> getPossibleValues(int x, int y) const;
		bool isAssignmentLegal(int x, int y, int val) const;
		void setTileValue(int x, int y, int val);
	private:
		Cluster clusters[3][3];
};


#endif // __BOARD_HPP