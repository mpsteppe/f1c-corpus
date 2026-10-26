bool sub_4B2F30()
{
  bool result; // al

  result = 0;
  if ( *(int *)dword_76926C > 0 )
    return (double)*(int *)dword_76926C * 0.050000001 > *(float *)(dword_75AAC4 + 18800)
                                                      * *(float *)(dword_75AAC4 + 18792);
  return result;
}
