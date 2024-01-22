//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once

#include <exception>

struct ExistingBranchInsertError : std::exception {
	ExistingBranchInsertError(){}
	const char* what() const noexcept override {
		return "Trying to add a branch with an already existing location";
	}
};
struct NonExistingBranchRemoveError : std::exception {
	NonExistingBranchRemoveError() {}
	const char* what() const noexcept override {
		return "Trying to remove a branch with a non existing location";
	}
};
struct NonExistingBranchRetrieveError : std::exception {
	NonExistingBranchRetrieveError() {}
	const char* what() const noexcept override {
		return "Trying to retrieve a branch with a non existing location";
	}
};
struct ExistingItemError : std::exception {
	ExistingItemError() {}
	const char* what() const noexcept override {
		return "Trying to add an item with an id already in the catalog";
	}
};
struct FullCatalogError : std::exception {
	FullCatalogError() {}
	const char* what() const noexcept override {
		return "Trying to add an item to a full catalog";
	}
};
struct NonExistingItemError : std::exception {
	NonExistingItemError() {}
	const char* what() const noexcept override {
		return "Trying to remove an item with a non existing id";
	}
};
struct NoneExistingItemTypeError : std::exception {
	NoneExistingItemTypeError() {}
	const char* what() const noexcept override {
		return "Trying to get an item with a non existing type";
	}
};
struct ConnectError : std::exception {
	ConnectError() {}
	const char* what() const noexcept override {
		return "Failed connection attempt";
	}
};