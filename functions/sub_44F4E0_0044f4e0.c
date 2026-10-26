int sub_44F4E0()
{
  FrustumViewportSetup(0, 0, dword_8B8DD4 - 1, dword_8B8DD8 - 1);
  CursorLoadImageALoaderWithHandleStorage(aCursor00Cur);
  CursorLoadImageALoaderWithHandleStorage(aCursor01Cur);
  CursorLoadImageALoaderWithHandleStorage(aCursor02Cur);
  CursorLoadImageALoaderWithHandleStorage(aCursor03Cur);
  CursorSelectorFromArray(0);
  return 0;
}
