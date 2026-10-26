void *__cdecl CallCatchBlock(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        const struct _s_FuncInfo *a4,
        void *a5,
        int a6,
        unsigned int a7)
{
  char v8; // al
  void *v9; // [esp+Ch] [ebp-2Ch]
  __ehstate_t state; // [esp+10h] [ebp-28h]
  int v11; // [esp+18h] [ebp-20h]
  int v12; // [esp+1Ch] [ebp-1Ch]

  state = a2[-1].state;
  v12 = _getptd()[27];
  v11 = _getptd()[28];
  _getptd()[27] = a1;
  _getptd()[28] = a3;
  v9 = _CallCatchBlock2(a2, a4, a5, a6, a7);
  a2[-1].state = state;
  _getptd()[27] = v12;
  _getptd()[28] = v11;
  if ( a1->ExceptionCode == -529697949 && a1->NumberParameters == 3 && a1->params.magicNumber == 429065504 && v9 )
  {
    v8 = _abnormal_termination();
    unknown_libname_184(a1, v8);
  }
  return v9;
}
