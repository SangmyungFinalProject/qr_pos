#include "qt_test.h"

string qr_code_str="";  //QR 코드 스캔한 값을 저장할 string을 전역변수로 선언


//int qr_scan()                                         //
//설명 : QR 코드 캡쳐하는 화면, OpenCV와 Zbar 라이브러리 사용//
int qr_scan()
{
   VideoCapture vc(0); // 0번 카메라 선택
   // cap.set(CV_CAP_PROP_FRAME_WIDTH,800); //화면 너비 조정
   // cap.set(CV_CAP_PROP_FRAME_HEIGHT,640);    //화면 길이 조정
   if (!vc.isOpened()) // 만약 카메라 연결이 안되었을 경우 에러 처리
   {
      cout << "Cannot open the video cam" << endl;
      return -1;
   }

   ImageScanner scanner;
   scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

   double dWidth = vc.get(CV_CAP_PROP_FRAME_WIDTH); //비디오 프레임의 너비
   double dHeight = vc.get(CV_CAP_PROP_FRAME_HEIGHT); //비디오 프레임의 높이

   cout << "Frame size : " << dWidth << " x " << dHeight << endl;

   namedWindow("QR Reader", CV_WINDOW_AUTOSIZE);

   while (1)
   {
      Mat frame;
      bool bSuccess = vc.read(frame); //카메라에서 프레임 읽어

      if (!bSuccess) //못 읽었으면 에러
      {
         cout << "Cannot read a frame from video stream" << endl;
         break;
      }

      Mat grey;
      cvtColor(frame, grey, CV_BGR2GRAY);

      int width = frame.cols;
      int height = frame.rows;
      uchar *raw = (uchar *)grey.data;

      // 이미지 wrap
      Image image(width, height, "Y800", raw, width * height);

      // 코드 스캔
      int n = scanner.scan(image);

      // 결과 추출
      for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
      {
         vector<Point> vp;

         //cout << "decoded " << symbol->get_type_name() << " symbol \"" << symbol->get_data() << "\"" << endl;
        //QR 코드 인식 결과 저장
        qr_code_str = symbol->get_data();
        cout << qr_code_str << endl;


        int n = symbol->get_location_size();
        for(int i=0;i<n;i++)
        {
           vp.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));
        }

        RotatedRect r = minAreaRect(vp);
        Point2f pts[4];
        r.points(pts);

        for(int i=0;i<4;i++){
          line(frame, pts[i], pts[(i+1)%4], Scalar(255,0,0), 3);
        }

        //cout<<"Angle: "<<r.angle<<endl;

        cvDestroyAllWindows();

        return 0;
     }

     imshow("QR Reader", frame); //화면에 카메라 윈도우 표시

     if (waitKey(30) == 27) //esc 입력 시 종료
     {
         cout << "esc key is pressed by user" << endl;
         cvDestroyAllWindows();
         break;
     }

   }
   return 0;
}
