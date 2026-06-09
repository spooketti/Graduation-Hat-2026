# Graduation Cap 2026

<img width="300" alt="image" src="https://github.com/user-attachments/assets/59fb7104-b930-4c3a-9051-dd4fa66a7032" />


When the occassion calls for it, I sometimes throw an Arduino in the mix of my life. That was a pretty great success last year, when I built a Christmas tree hat with lights on it,

<img src="https://github.com/spooketti/spooketti/blob/main/pfp/other/dog.png" width=160>

So I thought this year I'd try it but with my graduation cap. People love to decorate their grad caps, so I got to work. Admittedly, I got to work 3 hours before the ceremony was ready (I forgot you could decorate your cap). For context, we are only allowed to wear our decorations post ceremony, so there wasn't any issue regarding the cap throw and needing to repair mid walk, etc.

But I hope the following README can be a lesson on why you buy parts and prepare, but you could also argue this was just a hackathon.

## Planning

I wasn't sure completley on what to do, but I knew it had something to do with LEDs or the LCD. I wasted a considerable amount of time stuck deciding, when I eventually thought to combine both. The LCD only takes about 6 pins, so I'd have a few leftover. That's when I eventually came across the idea of turning the tassel with a servo motor. My plan was to then combine an LCD, LEDs, and a servo.

In terms of what will go on board, the baseplate, the servo motor, battery, Arduino, and Breadboard in a possible formation such as this

<img width="400" alt="image" src="https://github.com/user-attachments/assets/c5734d8b-e562-49df-866f-2827cf8931ca" />


## Code

The script was the easiest part, it just prints to the LCD display after picking a random quote, (the quotes themselves have data with them associated with how long they are on screen and whether they wipe the screen). After the quote is printed, the lights turn on and the tassel servo sweeps. (refer to hardware.ino)

# The Build

## The Tassel Sweeper

The plan was to have a baseplate to attach to the top of the cap. I didn't have many parts on hand with the time restriction so a piece of cardboard had to do. With that the first component that was the easiest to build was the servo sweeper. I found some disposable chopsticks and with some tape struck this together. 
<img width="1108" height="622" alt="image" src="https://github.com/user-attachments/assets/88e6587f-b187-450a-abc1-363f1116cf43" />

Admittedly not my best work, but it's important instead of looks to first understand this is where the first mistake I made was. The torque on the bar was going to be too heavy, and it ultimately did eventually fail in the end. If I could have gone back I would have used a counter weight or would have put the bar in the center to reduce the moment of inertia of having to rotate an entire bar. The paper towel at the end is just to stop the tassel from falling off, but in retrospect it would have been smarter to just have taped the tassel on post ceremony. The only part I would say was a good choice was planning around it sweeping on the back of the cap as to dodge colliding with wiring.

The LCD took at least an hour to wire given how specific the wiring is, but there were key mistakes made as well.

## The LCD

The LCD took up many ports and space on the breadboard, alongside being a huge point of possible failure as if a wire goes loose, there is a chance the system completely fails. The only issue I'd say in retrospect was not using a resistor on the LCD screen. On the A pin of the LCD, it is not meant to have the 5V line directly connected to it; that would be the only thing I'd fix outside of being too tall for anyone to read it. I would attach a picture of the LCD printing text, but at the time of writing I've already disassembled the parts and only have a low quality picture to show for it, so here is the best I can give. 
<img width="1117" height="611" alt="image" src="https://github.com/user-attachments/assets/82113e6c-aa07-46a8-8857-108470330014" />
(There is a red warning sign on the simulation because there isn't a resistor on the backlight)

## The motor... (LEDs)

There initially wasn't originally going to be a motor onboard, but unfortunatley as I was attaching the lights, I ran out of wires. The only alternative solution I could think of was to use a motor as a wire. Funnily enough, it actually worked.
<img width="1578" height="316" alt="image" src="https://github.com/user-attachments/assets/8607627a-124d-46a4-a4f1-e05cdc151e48" />

When all was said and done, it for the most part wasn't that bad, it was scrappy, but it worked. Ultimately, even thought it wasn't as grand as I would have hoped, I learned a bit and I think having thought of the optimizations that could have made it better was half the fun of it.

The repo name is 2026 afterall, maybe 2030 will see better results

<img width="535" height="601" alt="image" src="https://github.com/user-attachments/assets/8265a974-9075-406f-8ebe-a914b5a85feb" />
