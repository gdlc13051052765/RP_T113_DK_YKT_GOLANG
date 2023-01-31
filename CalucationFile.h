#include "string.h"
#include <stdint.h>
#include <unistd.h>

		 
uint8_t   	BytesCheckSum(uint8_t *,uint8_t);//闂傚倸鍊风粈渚€骞栭銈囩煓闁告洦鍘藉畷鍙夌節闂堟侗鍎愰柛瀣戠换娑㈠幢濡纰嶅┑锛勫仒缁瑩骞冨鈧幃娆撳箵閹哄棙瀵栨繝寰枫倕鐨洪柛蹇斆锝夊醇閺囩偤鍞跺銈嗗笂缁€渚€顢旈敓锟�
uint8_t     BytesComp( uint8_t * ,uint8_t *,uint8_t);//闂傚倷娴囬褏鈧稈鏅濈划娆撳箳濡炲皷鍋撻崘顔奸唶闁靛鍠楅弲鐐寸箾鏉堝墽鍒版繝鈧柆宥呯厺闁哄啫鐗婇悡鏇熺箾閸℃绂嬫俊鑼劋娣囧﹪鎳犻鈧崢瀵糕偓娈垮枛閻栫厧鐣烽悡搴樻斀闁糕剝顭囨禒宀€绱撻崒娆愮グ濡炴潙鎽滈幑銏ゅ磼閻戝洨绋忛梺闈涚箞閸婃牠寮查弻銉︾厱闁靛鍨冲畝娑㈡煕鐎ｎ偅灏摶锝囩磽娴ｅ鐓庮潩閿曞倹鈷戦柛婵嗗閳ь剙婀遍埀顒傜懗閸涱垳鐒奸梺閫炲秵瀚�0
uint8_t	    BCD_String_Diag(uint8_t * ,uint8_t);//BCD闂傚倸鍊烽悞锕€顪冮崸妤€绐楅柡鍥╁Х閻棗銆掑锝呬壕闂佽鍣ｇ紓姘端囩€靛摜纾兼い鏇炴噹瀵噣鏌℃担绋库偓鍧楀箠濡ゅ拋鏁嶉柨婵嗘閸╃偤姊绘担钘夊惞濠殿喗娼欑叅闁靛牆顦伴弲婵嬫煏婢跺棙娅呴柦鍐枛閺屻劑鎮ら崒娑橆伓
uint8_t     BCDToHex(uint8_t  );
uint8_t     HexToBCD(uint8_t  );
uint32_t	ChgBCDStringToUlong(uint8_t * ,uint8_t);//BCD闂傚倸鍊烽悞锕€顪冮崸妤€绐楅柡鍥╁Х閻棗銆掑锝呬壕闂佽鍣ｇ紓姘端囩€靛摜纾兼い鏇炴噹瀵噣鏌℃担绋库偓鍧楀箠濡ゅ拋鏁嶉柨婵嗘閸╃偤姊绘担鍛婃儓妞わ箓浜跺畷鏇㈠箛閺夎法顦┑顔斤供閸撴盯寮抽敃鍌涚厱婵炲棗娴氬Σ娲煃缂佹ɑ顥堥柡宀嬬秮楠炲鎮欓崱妯虹仴闁崇粯鎸荤换婵嗩潩椤撶姴骞堥梻渚€娼ф灙闁稿孩妞藉畷鏇㈠箛閻楀牏鍘搁梺绯曟閸樼晫鈧熬鎷�
uint8_t	    CalCheckSum(uint8_t * ,uint8_t);//闂傚倷娴囧畷鍨叏瀹曞洦顐介柕鍫濇处椤洟鏌￠崶銉ョ仾闁稿鏅涢埞鎴︽偐鐎圭姴顥濋梺鍛婂姀閸嬫捇姊绘担鑺ョ《闁哥姵鎸婚幈銊ョ暋閹殿喗娈鹃梺鎸庣箓椤︿即鎮￠弴鐔虹瘈濠电姴鍊搁弳鐔兼煟閹烘垶鍋ラ柡宀€鍠栧畷娆撳Χ閸℃浼�
void	    ChgUlongToBCDString( uint32_t ,uint8_t * ,uint8_t );
void	    ChgIntToStrings(uint16_t	ii,uint8_t * ptr);
uint32_t	ChgInputToUlong(uint8_t * ,uint8_t);//闂傚倷绀侀幖顐λ囬鐐村亱濠电姴娲ょ粻浼存煙闂傚顦﹂柣顓燁殜閺屾盯鍩勯崘顏佸闂佺ǹ楠哥粔褰掑蓟濞戙垹鍗抽柕濞垮劚椤亜鈹戦悙鑼闁绘牕銈搁獮鍐ㄎ旈埀顒勫煡婢跺ň鏋庢俊顖濆吹閺嗩垱绻濋悽闈涗沪婵炲吋鐟ヨ灋婵犻潧顑囧畵渚€鏌熸潏鎹愵吅缂傚秵鐗楅妵鍕箼閸曨厾锛熷銈忕細閸楀啿顫忔繝姘＜婵°倐鍋撳ù婊堢畺濮婃椽宕烽鈧崷顓涘亾濞戞帗娅呴柍缁樻崌閹筹繝濡堕崱妤佺€鹃梺姹囧焺閸ㄥジ宕板Δ鍐ｅ亾濮樼偓瀚�
uint32_t 	GetU32_HiLo(uint8_t *);
uint16_t 	GetU16_HiLo(uint8_t *);
void 	    PutU32_HiLo(uint8_t *,uint32_t);
void 	    PutU16_HiLo(uint8_t *,uint16_t);
void	    FormatBuffer(uint8_t,uint8_t * ,uint8_t *);
uint32_t	ChgKeyStringToUlong(uint8_t * ptr ,uint8_t Len);
uint32_t	ChgStringsToInt(uint8_t * ptr);
uint16_t    DoubleBigToSmall(uint16_t a);
void        HexGroupToHexString(uint8_t *data,uint8_t *dst,uint16_t len);
uint16_t    HexStringToHexGroup(uint8_t *,uint8_t *,uint16_t);
uint8_t     AddQuFan(uint8_t *str,uint8_t len);//缂傚倸鍊搁崐椋庢濮樿鲸鍏滈柟闂寸閸ㄥ倿鏌ｅΔ鈧悧濠囧矗韫囨稒鐓熼柟閭﹀墯閹牊淇婇悙鎵煓闁诡喗锕㈤幃娆撴嚋濞堟寧顥夌紓鍌欑劍瑜板啫顭囬敓鐘茶摕婵炴垶菤閺嬪孩绻涢崱妯哄妞ゅ骏鎷�
uint32_t    ChgBCDStringTouint32_t(uint8_t * ptr ,uint8_t Len);//BCD闂傚倷鐒﹀鍧楀窗閺囩姷鐭嗗〒姘ｅ亾闁诡噣缂氶ˇ瀵哥磼椤曞懎寮柡浣稿€块幊妤咁敍閿濆棜鍩為梻浣告惈椤﹂亶宕曢幇鏉跨婵﹩鍓涢弳锕傛煕濞嗗浚妲洪柍缁樻閺岋綁骞嬮悙鍡樺灥閳绘挻绻濆顓犲幈闂侀潧枪閸庢椽宕曢幇鐗堢厸闁糕槅鍘界€氾拷
void        Chguint32_tToBCDString( uint32_t iii,uint8_t * ptr,uint8_t Len);
void        ChgTimeToRecordDatas(uint8_t * Timeptr,uint8_t * ptr);
 