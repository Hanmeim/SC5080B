enum pins{
//%
}
//% color="#23009D" iconWidth=50 iconHeight=40
namespace c_SC5080b  {
    //% block="SC5080B初始化 引脚S[PINS] 引脚B[PINB]" blocktype="command"
    //% PINS.shadow="dropdown" PINS.options="PIN_DigitalWrite"
    //% PINB.shadow="dropdown" PINB.options="PIN_DigitalWrite"
     export function SC5080B_init(parameter: any, block: any) {
        let pin_s = parameter.PINS.code
        let pin_b = parameter.PINB.code
        Generator.addInclude("SC5080B_include", "#include <SC5080B_Voice.h>");
        Generator.addObject("my_Voice",`SC5080B_Voice`, `my_Voice(${pin_s},${pin_b});`);
        Generator.addSetup("Voice_init", `my_Voice.init();`)
    }

    //% block="SC5080B语音模块播放声音：[WORD]" blockType="command"
    //% WORD.shadow="dropdown" WORD.options="LIST_voiceList"
    export function SC5080B_word(parameter: any, block: any) {
        let word_num = parameter.WORD.code
        Generator.addCode(`my_Voice.speakVoiceWord(${word_num});`);
    }

    //% block="SC5080B语音模块播放语音库中第[SERI]条语音" blockType="command"
    //% SERI.shadow="range" SERI.params.min=1 SERI.params.max=99 SERI.defl=1
    export function SC5080B_word_seri(parameter: any, block: any) {
        let word_seri = parameter.SERI.code
        Generator.addCode(`my_Voice.speakVoiceWord(${word_seri});`);
    }

    //% block="SC5080B语音模块播放数字 [NUM]" blockType="command"
    //% NUM.shadow="range" NUM.params.min=1 NUM.params.max=9999 NUM.defl="40"
    export function SC5080B_number(parameter: any, block: any) {
        let voice_num = parameter.NUM.code;
        Generator.addCode(`my_Voice.speakVoiceNumber(${voice_num});`);
    }
}
