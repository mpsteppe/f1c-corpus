int sub_56D8F0()
{
  int result; // eax
  int v1; // esi

  result = sub_587DB0(aPmodelErrorTxt, aA);
  v1 = result;
  if ( result )
  {
    StringFormatWithNestedIO(result, aS_4);
    return FileCloseWithLock(v1);
  }
  return result;
}

