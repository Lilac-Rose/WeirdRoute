#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include <Geode/binding/GJGameLevel.hpp>

using namespace geode::prelude;

class $modify(DeltaBestPlayLayer, PlayLayer) {
	struct Fields {
		bool m_playedThisAttempt = false;
	};

	void resetLevel() {
		PlayLayer::resetLevel();
		m_fields->m_playedThisAttempt = false;
	}

	void levelComplete() {
		PlayLayer::levelComplete();
		auto play_reversed_jingle = Mod::get()->getSettingValue<bool>("reversed_weird_route_on_complete");
		auto volume = Mod::get()->getSettingValue<double>("volume");
		if (play_reversed_jingle) {
			FMODAudioEngine::sharedEngine()->playEffect(
				"weird-route-reversed.ogg"_spr,
				1.0f,
				1.0f,
				static_cast<float>(volume)
			)
		}
	}

	void updateProgressbar() {
		PlayLayer::updateProgressbar();

		if (m_fields->m_playedThisAttempt || m_isPracticeMode || !m_level) {
			return;
		}

		auto best = static_cast<float>(m_level->m_normalPercent.value());
		if (best > 0.f && this->getCurrentPercent() > best) {
			m_fields->m_playedThisAttempt = true;

			auto volume = Mod::get()->getSettingValue<double>("volume");
			FMODAudioEngine::sharedEngine()->playEffect(
				"weird-route.ogg"_spr,
				1.0f,
				1.0f,
				static_cast<float>(volume)
			);
		}
	}
};
