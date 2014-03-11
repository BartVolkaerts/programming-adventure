import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Spel extends JPanel 
{
  private int aantal;
  private int juisteKnop;
  private int score;

  private ArrayList<JButton> buttonList; 
  private JLabel scoreLabel;

  public Spel()
  {
    while(true)
    {
      try
      {
        aantal = Integer.parseInt(JOptionPane.showInputDialog(this, "Hoeveel knoppen?"));
      }
      catch (NumberFormatException fout)
      {
        JOptionPane.showMessageDialog(null, "Gelieve een getal in te voeren", "Oeps..",JOptionPane.INFORMATION_MESSAGE);    
        continue;
      }
      break;
    }
    score = aantal;
    juisteKnop = 1 + (int)(Math.random() * ((aantal - 1) + 1));
    scoreLabel = new JLabel(Integer.toString(aantal));
    buttonList = new ArrayList<JButton>();
    for(int i = 1; i <= aantal; ++i)
    {
      buttonList.add(new JButton("" + i));
    }
    Iterator it = buttonList.iterator();
    setLayout(new GridLayout(10,10));
    while(it.hasNext())
    {
      JButton temp = (JButton)it.next();
      temp.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          JButton source = (JButton)e.getSource();
          if(source.getText().equals(Integer.toString(juisteKnop)))
          {
            geraden();
            System.exit(0);
          }
          else
          {
            source.setVisible(false);
            --score;
            scoreLabel.setText("" + score + "/" + aantal);
          }
        }});
      add(temp);
    }
    add(scoreLabel);
  }

  private void geraden()
  {
      JOptionPane.showMessageDialog(null, score*(100/aantal) + "%", "Hoera!",JOptionPane.INFORMATION_MESSAGE);    
  }

  public static void main(String[] args)
  {
    JFrame jf = new JFrame("Raad de knop");
    jf.getContentPane().add(new Spel());
    jf.pack();
    jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    jf.setVisible(true);
    
  }
}
