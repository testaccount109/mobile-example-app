set(headers ${headers} ../src/Menu/View
)
set(currsources
  ../src/Menu/View/CMakeLists.txt
  ../src/Menu/View/IMenuModel.h
  ../src/Menu/View/IMenuOption.h
  ../src/Menu/View/IMenuOptionsModel.h
  ../src/Menu/View/IMenuSectionsViewModel.h
  ../src/Menu/View/IMenuSectionViewModel.h
  ../src/Menu/View/IMenuView.h
  ../src/Menu/View/IMenuViewModel.h
  ../src/Menu/View/IMenuReactionModel.h
  ../src/Menu/View/MenuController.cpp
  ../src/Menu/View/MenuController.h
  ../src/Menu/View/MenuItemModel.cpp
  ../src/Menu/View/MenuItemModel.h
  ../src/Menu/View/MenuJsonSerializer.h
  ../src/Menu/View/MenuModel.h
  ../src/Menu/View/MenuOpenableControl.cpp
  ../src/Menu/View/MenuOpenableControl.h
  ../src/Menu/View/MenuOptionsModel.cpp
  ../src/Menu/View/MenuOptionsModel.h
  ../src/Menu/View/MenuScreenControl.cpp
  ../src/Menu/View/MenuScreenControl.h
  ../src/Menu/View/MenuSectionsViewModel.cpp
  ../src/Menu/View/MenuSectionsViewModel.h
  ../src/Menu/View/MenuSectionViewModel.cpp
  ../src/Menu/View/MenuSectionViewModel.h
  ../src/Menu/View/MenuViewModel.cpp
  ../src/Menu/View/MenuViewModel.h
  ../src/Menu/View/SortedMenuComparisonFunctions.cpp
  ../src/Menu/View/SortedMenuComparisonFunctions.h
  ../src/Menu/View/SortedMenuModel.cpp
  ../src/Menu/View/SortedMenuModel.h
)
set(sources ${sources} ${currsources})
source_group(\\src\\Menu\\View FILES ${currsources})
