int __stdcall sub_49AD50(LPCSTR lpSrcStr)
{
  int result; // eax

  if ( lpSrcStr )
  {
    sub_589901(lpSrcStr);
    return StringCopyWithBufferRealloc(lpSrcStr);
  }
  return result;
}

