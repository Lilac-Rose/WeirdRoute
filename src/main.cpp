#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>

using namespace geode::prelude;

class $modify(DeltaBestPlayLayer, PlayLayer) {
	void showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle) {
		PlayLayer::showNewBest(newReward, orbs, diamonds, demonKey, noRetry, noTitle);

		auto volume = Mod::get()->getSettingValue<double>("volume");
		FMODAudioEngine::sharedEngine()->playEffect(
			"weird-route.ogg"_spr,
			1.0f,
			1.0f,
			static_cast<float>(volume)
		);
	}
};
