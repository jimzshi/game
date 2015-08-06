#include "libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include <memory>

#ifdef ZKS_OS_WINDOWS_
#include <filesystem>
namespace sys = std::tr2::sys;
#endif // ZKS_OS_WINDOWS_

using namespace std;


//zks::simlog g_logger;

#ifndef USE_GUI
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << argv[0] << " [solve|generate|count] log.ini game-file" << endl;
        return 0;
    }
    g_logger.configure(argv[2]);
    g_logger.reset();

    zks::u8string cmd{argv[1]};
    cmd = cmd.tolower();
    ZKS_INFO(g_logger, "main", "read in command: %s %s %s %s", argv[0], argv[1], argv[2], argv[3]);
    int ret { -2 };
    if(cmd=="solve") {
        ret = zks::game::sudoku::solve(zks::game::sudoku::solver_thread, argv[3]);
    } else if(cmd == "generate") {
        ret = zks::game::sudoku::generate(zks::game::sudoku::generate_thread, 10);
    } else if(cmd == "count") {
        ret = zks::game::sudoku::solve(zks::game::sudoku::count_thread, argv[3]);
    } else {
        ZKS_ERROR(g_logger, "main", "can not interpret cmd:%s, (should be one of solve/generate/count).", cmd.c_str());
        ret = -3;
    }

    ZKS_INFO(g_logger, "main", "return value: %d", ret);

    return 0;
}
#else

#include "TCMainFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/intl.h"


static const wxLanguage langIds[] =
{
	wxLANGUAGE_DEFAULT,
	wxLANGUAGE_ENGLISH,
	//wxLANGUAGE_ENGLISH_US,
	wxLANGUAGE_CHINESE_SIMPLIFIED,
	//wxLANGUAGE_FRENCH,
	//wxLANGUAGE_ITALIAN,
	//wxLANGUAGE_GERMAN,
	//wxLANGUAGE_RUSSIAN,
	//wxLANGUAGE_BULGARIAN,
	//wxLANGUAGE_CZECH,
	//wxLANGUAGE_POLISH,
	//wxLANGUAGE_SWEDISH,
	//wxLANGUAGE_JAPANESE,
	//wxLANGUAGE_GEORGIAN,
	//wxLANGUAGE_ARABIC,
	//wxLANGUAGE_ARABIC_EGYPT
};


const wxString langNames[] =
{
	"System default",
	"English",
	//"English (U.S.)",
	"Chinese",
	//"French",
	//"Italian",
	//"German",
	//"Russian",
	//"Bulgarian",
	//"Czech",
	//"Polish",
	//"Swedish",
	//"Japanese",
	//"Georgian",
	//"Arabic",
	//"Arabic (Egypt)"
};

// the arrays must be in sync
wxCOMPILE_TIME_ASSERT(WXSIZEOF(langNames) == WXSIZEOF(langIds),
	LangArraysMismatch);

class MyApp : public wxApp
{
public:

	MyApp() { m_lang = wxLANGUAGE_UNKNOWN; }

    virtual bool OnInit(){
		if (!wxApp::OnInit())
			return false;
#ifdef ZKS_OS_WINDOWS_
		auto wp = sys::current_path();
		wp /= "../etc/TxtConverter.ini";
		if (m_conf.parse(wp.generic_string()) < 0 || !m_conf.has_option("general", "lang")) {
			wxLogWarning(wxString::Format(_("Can't read in setting file: '%s'"), wp.generic_string()));
			m_lang = wxLANGUAGE_UNKNOWN;
		}
#else // ZKS_OS_WINDOWS_
		if (m_conf.parse("../etc/TxtConverter.ini") < 0 || !m_conf.has_option("general", "lang")) {
			wxLogWarning(wxString::Format(_("Can't read in setting file: '%s'"), "../etc/TxtConverter.ini"));
			m_lang = wxLANGUAGE_UNKNOWN;
		}
#endif // ZKS_OS_WINDOWS_
		else {
			zks::u8string lang;
			m_conf.option("General", "lang", &lang);
			for (size_t i = 0; i < WXSIZEOF(langNames); ++i) {
				if (langNames[i].ToStdString() == lang.str()) {
					m_lang = langIds[i];
				}
			}
		}

		if (m_lang == wxLANGUAGE_UNKNOWN)
		{
			int lng = wxGetSingleChoiceIndex
				(
					_("Please choose language:"),
					_("Language"),
					WXSIZEOF(langNames),
					langNames
					);
			m_lang = lng == -1 ? wxLANGUAGE_DEFAULT : langIds[lng];
		}

		if (!m_locale.Init(m_lang, wxLOCALE_DONT_LOAD_DEFAULT))
		{
			wxLogWarning(_("This language is not supported by the system."));
		}

		wxLocale::AddCatalogLookupPathPrefix("../share/locale");

		const wxLanguageInfo* pInfo = wxLocale::GetLanguageInfo(m_lang);
		if (!m_locale.AddCatalog("TxtConverter"))
		{
			wxLogError(_("Couldn't find/load the 'TxtConverter' catalog for locale '%s'."),
				pInfo ? pInfo->GetLocaleName() : _("unknown"));
		}

		// Now try to add wxstd.mo so that loading "NOTEXIST.ING" file will produce
		// a localized error message:
		m_locale.AddCatalog("wxstd");

        MyFrame *frame = new MyFrame(_("Txt Converter 0.1 Beta"), wxDefaultPosition, wxDefaultSize);
        frame->Show(true);
        return true;
    }
protected:
	wxLanguage m_lang;  // language specified by user
	wxLocale m_locale;  // locale we'll be using
	zks::simconf m_conf;
};

wxDECLARE_APP(MyApp);

wxIMPLEMENT_WXWIN_MAIN_CONSOLE

wxIMPLEMENT_APP_NO_MAIN(MyApp);

#endif //USE_GUI
