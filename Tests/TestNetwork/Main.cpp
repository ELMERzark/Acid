#include <iostream>
#include <thread>
#include <Engine/Log.hpp>
#include <Network/Ftp/Ftp.hpp>
#include <Network/Http/Http.hpp>
#include <Network/Udp/UdpSocket.hpp>
#include <Network/Packet.hpp>
#include <Files/FileSystem.hpp>

using namespace acid;

int main(int argc, char **argv)
{
	// TODO: Download a ZIP from Google Drive.
	/*{
		auto http = Http("http://drive.google.com/");

		HttpRequest request;
		request.SetMethod(HttpRequest::Method::Get);
		request.SetUri("/uc?id=1LLymFp9BRrSje7jaGJdHBraW0BVpZ2-K&export=download");
		request.SetHttpVersion(1, 1); // HTTP 1.1
		request.SetField("From", "me");
		request.SetField("Content-Type", "application/vnd.google-apps.file");

		auto page = http.SendRequest(request);
		uint32_t fileSize = page.GetBody().size();

		const auto &fileContainer = page.GetBody();
		std::ofstream file(FileSystem::GetWorkingDirectory() + "/Data-Sponza.zip", std::ios::out | std::ios::binary);
		file.write(fileContainer.c_str(), fileSize);
		file.close();
	}*/

	// https://www.sfml-dev.org/tutorials/2.5/network-http.php
	{
		auto http = Http("http://equilibrium.games/");

		HttpRequest request;
		request.SetMethod(HttpRequest::Method::Post);
		request.SetUri("/devblog/");
		request.SetHttpVersion(1, 1); // HTTP 1.1
		request.SetField("From", "me");
		request.SetField("Content-Type", "application/x-www-form-urlencoded");
		request.SetBody("para1=value1&param2=value2");

		auto response = http.SendRequest(request);
		Log::Out("Status: %i\n", response.GetStatus());
		Log::Out("HTTP version: %i.%i\n", response.GetMajorHttpVersion(), response.GetMinorHttpVersion());
		Log::Out("Content-Type header: %s\n", response.GetField("Content-Type").c_str());
		Log::Out("Body: %s\n", response.GetBody().c_str());
	}
	// https://www.sfml-dev.org/tutorials/2.5/network-ftp.php
	/*{
		Ftp ftp;
		ftp.Connect(IpAddress("ftp.myserver.org"), 21);
		ftp.Login("username", "password");
		ftp.KeepAlive();

		FtpResponseDirectory response = ftp.GetWorkingDirectory();

		if (response.IsOk())
		{
			Log::Out("Current directory: %s\n", response.GetDirectory());
		}

		ftp.Download("remote_file_name.txt", "local/destination/path", FtpTransfer::Mode::Ascii);
		ftp.Upload("local_file_name.pdf", "remote/destination/path", FtpTransfer::Mode::Binary);

		ftp.Disconnect();
	}*/

	/*UdpSocket socket = UdpSocket();

	std::string name = "Hello world";
	uint32_t a = 420;
	float b = 6.9f;
	Vector3 c = Vector3(8.1f, -9.11f, 2.083f);

	Packet packet = Packet();
	packet << name << a << b << c; // Sending data.
	packet >> name >> a >> b >> c; // Receiving data.

	IpAddress recipient = IpAddress("172.168.0.9");
	unsigned short port = 54000;
	if (socket.Send(packet.GetData(), packet.GetDataSize(), recipient, port) != SocketStatus::Done)
	{
		Log::Error("Error OH NO\n");
		// error...
	}*/

	// Pauses the console.
	std::cout << "Press enter to continue...";
	std::cin.get();
	return EXIT_SUCCESS;
}
