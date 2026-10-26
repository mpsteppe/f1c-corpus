char sub_4628A0()
{
  float v1; // [esp+0h] [ebp-238h]
  _BYTE v2[128]; // [esp+8h] [ebp-230h] BYREF
  _DWORD v3[108]; // [esp+88h] [ebp-1B0h] BYREF

  FAILWRONGDESCRIPTION(v2);
  if ( !(unsigned __int8)UniqueID(v2) )
    return 0;
  ConditionalStateDispatch(0);
  SessionConfigBuilder((int)v2);
  BufferSendWithLocks(dword_7CD25C, (int)v2);
  v1 = dbl_8AFEA0;
  ProgressBarEventEncode(4, 5, 0, 0, LODWORD(v1), 1);
  TextureCreationWrapper(dword_7CD25C, v3, 2, -1, -1);
  SystemOSAPICall_0dc0(&unk_7CE24D);
  return 1;
}
