class ShowMemberRentHistory {
public:
	showRentHistory() { getUserIdFromSession(); bikeInfos = getBikeInfosByUserId();  showResult(); }
};