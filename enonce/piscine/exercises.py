class Exercises():
    name = ""
    required = ""

    def __init__(self):
        required = ""


def check(name, list):
    for ex in list:
        if ex.name == name:
            return False
    return True


def getHeader(name):
    header = {
        "authority": "intra.forge.epita.fr",
        "method": "GET",
        "path": "/epita-ing-assistants-acu/piscine-2025/root/exercises/exercises-c/+name+/+name+/"+name+".pdf",
        "scheme": "https",
        "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
        "accept-encoding": "gzip, deflate, br",
        "accept-language": "fr,fr-FR;q=0.9,en-US;q=0.8,en;q=0.7",
        "cookie": "_gcl_au=1.1.515055253.1660813944; atidvisitor=%7B%22name%22%3A%22atidvisitor%22%2C%22val%22%3A%7B%22vrn%22%3A%22-226990-%22%7D%2C%22options%22%3A%7B%22path%22%3A%22%2F%22%2C%22session%22%3A15724800%2C%22end%22%3A15724800%7D%7D; _ga=GA1.2.2026249645.1660813945; _ga_XKKFXN2BFT=GS1.1.1660813945.1.1.1660813993.0.0.0; q_session=eyJhbGciOiJSUzI1NiIsImtpZCI6IjJjOTY5NGNlMzRmNDlmZjMyMjIyYmJmY2UwOTg0YmE0In0.eyJpc3MiOiJodHRwczovL2NyaS5lcGl0YS5mciIsInN1YiI6InF1ZW50aW4ua3V0dGxlciIsImF1ZCI6IjgyNTg4NSIsImV4cCI6MTY2NzE0NDMwOSwiaWF0IjoxNjY3MTQzNzA5LCJhdXRoX3RpbWUiOjE2NjY2ODg2NDgsImF0X2hhc2giOiJFb1ptcnVqeE10N0pMRXFPNV9fU3pRIiwiZ2l2ZW5fbmFtZSI6IlF1ZW50aW4iLCJmYW1pbHlfbmFtZSI6Ikt1dHRsZXIiLCJuaWNrbmFtZSI6InF1ZW50aW4ua3V0dGxlciIsInVpZCI6MjUzMTksImdpZCI6MTUwMDAsImdyb3VwcyI6W3sic2x1ZyI6InN0ZyIsImdpZCI6bnVsbCwibmFtZSI6IlN0cmFzYm91cmciLCJraW5kIjoiY2FtcHVzIiwicHJpdmF0ZSI6ZmFsc2V9LHsic2x1ZyI6ImluZy1pbmcxLXM1LXRjLWhtIiwiZ2lkIjpudWxsLCJuYW1lIjoiUzUgSGFybW9uaXNhdGlvbiBtYXRoXHUwMGU5bWF0aXF1ZXMiLCJraW5kIjoiY291cnNlIiwicHJpdmF0ZSI6ZmFsc2V9LHsic2x1ZyI6ImluZyIsImdpZCI6bnVsbCwibmFtZSI6IkN5Y2xlIGluZ1x1MDBlOW5pZXVyIiwia2luZCI6ImN1cnJpY3VsdW0iLCJwcml2YXRlIjpmYWxzZX0seyJzbHVnIjoic3R1ZGVudHMiLCJnaWQiOjE1MDAwLCJuYW1lIjoiXHUwMGM5dHVkaWFudHMiLCJraW5kIjoib3RoZXIiLCJwcml2YXRlIjpmYWxzZX0seyJzbHVnIjoiaW5nLWluZzEtc3RnIiwiZ2lkIjpudWxsLCJuYW1lIjoiSU5HMSBTdHJhc2JvdXJnIiwia2luZCI6Im90aGVyIiwicHJpdmF0ZSI6ZmFsc2V9LHsic2x1ZyI6ImluZy1pbmcxLXM1LXN0ZyIsImdpZCI6bnVsbCwibmFtZSI6IlM1IFN0cmFzYm91cmciLCJraW5kIjoib3RoZXIiLCJwcml2YXRlIjpmYWxzZX0seyJzbHVnIjoiaW5nLWluZzEtczUiLCJnaWQiOm51bGwsIm5hbWUiOiJTNSIsImtpbmQiOiJzZW1lc3RlciIsInByaXZhdGUiOmZhbHNlfSx7InNsdWciOiJ1c2VycyIsImdpZCI6MTAwLCJuYW1lIjoiVXRpbGlzYXRldXJzIiwia2luZCI6InN5c3RlbSIsInByaXZhdGUiOmZhbHNlfSx7InNsdWciOiJpbmctaW5nMSIsImdpZCI6bnVsbCwibmFtZSI6IklORzEiLCJraW5kIjoieWVhciIsInByaXZhdGUiOmZhbHNlfV0sImNhbXB1c2VzIjpbInN0ZyJdLCJncmFkdWF0aW9uX3llYXJzIjpbMjAyNV0sInBpY3R1cmUiOiJodHRwczovL3Bob3Rvcy5jcmkuZXBpdGEuZnIvcXVlbnRpbi5rdXR0bGVyIiwicGljdHVyZV9zcXVhcmUiOiJodHRwczovL3Bob3Rvcy5jcmkuZXBpdGEuZnIvc3F1YXJlL3F1ZW50aW4ua3V0dGxlciIsInBpY3R1cmVfdGh1bWIiOiJodHRwczovL3Bob3Rvcy5jcmkuZXBpdGEuZnIvdGh1bWIvcXVlbnRpbi5rdXR0bGVyIiwibmFtZSI6IlF1ZW50aW4gS3V0dGxlciIsInByZWZlcnJlZF91c2VybmFtZSI6InF1ZW50aW4ua3V0dGxlciIsInpvbmVpbmZvIjoiRXVyb3BlL1BhcmlzIn0.YtQ4ZfNKcWukEeHqasf62qNbCoL-MjMuKgJ5Css4XNSk7KkIGOwfFjTaUSsLA-Duf1hYSZbTZF1RylK8h2TQcdY-iIr3Ptui6NuqrL8tpvUEBlRn8m76iP1SB_UE_uoF-51bK3DUmCBhcyPYAh7H08DuMTgQus76mesTttXVTzU|005035b5e2744c7a9c479b5b23712414|d429b511a44b41a984d674e7617c4349",
        "sec-ch-ua": '"Google Chrome";v="107", "Chromium";v="107", "Not=A?Brand";v="24"',
        "sec-ch-ua-mobile": "?1",
        "sec-ch-ua-platform": '"Android"',
        "sec-fetch-dest": "document",
        "sec-fetch-mode": "navigate",
        "sec-fetch-site": "none",
        "sec-fetch-user": "?1",
        "upgrade-insecure-requests": "1",
        "user-agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Mobile Safari/537.36"
    }
    return header